# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

### Describe the effect each of the P, I, D components had in your implementation
The formula for PID controller is as follows:
![Formula of PID controller](https://wikimedia.org/api/rest_v1/media/math/render/svg/69072d4013ea8f14ab59a8283ef216fb958870b2)  
where ![Kp](https://wikimedia.org/api/rest_v1/media/math/render/svg/38e48c8af23d23eac3ba0d0fa7b334ce714db514), ![Pi](https://wikimedia.org/api/rest_v1/media/math/render/svg/447e4c9812c16d055852adb0ecde083d83a1c523) and ![Pd](https://wikimedia.org/api/rest_v1/media/math/render/svg/03b0cbd335ce887bc04d0f609abc42e613af0727) are non-zero coefficients for proportional, integral and derivative terms of the controller.  
**P** produces steering value proportional to the cross-track error. If only this term is used, the controller tends to overshoot (the car will miss the reference trajectory).  
**I** allows to deal with systematic accumulated error. When "I" term is used alone, the car leaves the road.  
**D** term deals with overshooting and car's oscillations. This component alone cannot provide smooth trajectory and the car reacty to small changes in the road curvature.

---

### Describe how the final hyperparameters were chosen
Initially I used hyperparameters suggested by Sebastian Thrun in his lecture (Kp=0.2; Ki=0.004; Kd=3.0). After that I tuned the parameters using "Twiddle" algorithm proposed by Sebastian Thrun. This is an automated trial and error method of parameter tuning which allows to reach a local minimum. The idea is in changing each parameter with a certain step and see how the error changes. This allows us to decide whether to increase, decrease the parameter's value, or remain unchanged.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
