#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function. 
  std::unique_lock<std::mutex> uLock(_mutex);
        _condition.wait(uLock, [this] { return !_queue.empty(); }); // pass unique lock to condition variable

        // remove last vector element from queue
        T msg = std::move(_queue.back());
        _queue.pop_back();
        return msg; 
}


template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
  
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);
        // add vector to queue
        _queue.emplace_back(std::move(msg));
        _condition.notify_one(); // notify client after pushing new Vehicle into vector
}


/* Implementation of class "TrafficLight" */




TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.
 /* while(true){
  		if(_trafficLightMessages.receive() == TrafficLightPhase::green ){
        	return;
        }
  	}
  */
  
  bool flag = true;

    while(flag){
        if (_trafficLightMessages.receive() == TrafficLightPhase::green){
            flag = false;
        }
    }  
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}


void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. To do this, use the thread queue in the base class. 
  threads.emplace_back(std::thread{&TrafficLight::cycleThroughPhases, this});
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    // and toggles the current phase of the traffic light between red and green and sends an update method 
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds. 
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles. 
   // ref: // https://knowledge.udacity.com/questions/96814
  // ref // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  //https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
  
  std::random_device rd;    // used as a seed for the random number engine
  std::mt19937 gen(rd());  //Std mersenne_twister_engine seeded with rd();
  std::uniform_real_distribution<> dis(4000.0, 6000.0); // generate a real no, double value in between 4.0 s to 6.0 s
  double range_cycle_duration = dis(gen); 
  auto previous_value = std::chrono::system_clock::now();
  
    while(true){
    	std::this_thread::sleep_for(std::chrono::milliseconds(1));
     // 
      auto present_value = std::chrono::system_clock::now();
      double cycle_duration = std::chrono::duration_cast<std::chrono::milliseconds>(present_value - previous_value).count();
      if( cycle_duration >= range_cycle_duration){
      	if(_currentPhase == TrafficLightPhase::green){
          	_currentPhase = TrafficLightPhase::red;	
       		 }
      	else {
      		_currentPhase = TrafficLightPhase::green;
      		}
      _trafficLightMessages.send(std::move(_currentPhase));
        // regenerate a time between 4-6 seconds or 4000-6000 ms
      std::random_device rd;    // used as a seed for the random number engine
 	  std::mt19937 gen(rd());  //Std mersenne_twister_engine seeded with rd();
  	  std::uniform_real_distribution<> dis(4000.0, 6000.0); 
      double range_cycle_duration = dis(gen);
      previous_value = std::chrono::system_clock::now(); //measure the time now when a new loop is starting inside          
      }                                                           //while loop
   }
}

