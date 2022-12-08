# Breathe Like You

## Contents
* [Introduction](#40)
* [Research Blog](#41)  
  * [Week 5](#42)
  * [Week 6](#43)
  * [Week 7](#44)
  * [Week 8](#45)
  * [Week 9](#46)
  * [Week 10](#47)
* [Reference](#48) 

<h2 id="40">Introductinon</h2>
Breathe Like You is an interactive art installation that reflects the relationship between two people based on their breathing rate.  

We use two PIR sensors and two analogue sound sensors as inputs, two led rings and a speaker as outputs to help two people feel the state they are in when they breathe at the same frequency.

📺 Here is a video of our project: https://youtu.be/TEn1UXd2_kI  

<h2 id="41">Research Blog</h2>
<h3 id="42">Week 5: Project Proposal</h3>
In the topic selection phase, we first sorted out the inputs and outputs that could be used, as follows.  
   
**Input:** temperature, distance, light sensitivity, pressure, infrared thermography, buttons, time data, etc.  
**Output:** changes in lights, object movement and rotation, changes in sound, visual screens, projection, etc.

### Brainstorm 🧠
#### Idea 1: Curtains of Homeland -from Yutian
As we have just come to live in London for a month or so, there is an eight hour jet lag between the UK and China. We thought about how we could use the installation to represent this distance in time and space from our family and friends. The idea was to use the time and light changes in China as input and transmit the data to London via the internet. And to create a curtain-like installation in London, where the arduino would control the oscillation of the cloth (using servos) and the lights based on the data from China. This breaks the 8-hour time difference and allows the audience to connect with their homeland on another level.
  
But given the difficulty, after we looked up the data we found it might be difficult to accomplish. So the idea was to collect time and light data only in London, with an 8-hour delay in data transmission to the cloth and lights, thus achieving a feeling of going back in time.
  
**Input:** time, distance, light sensitivity, temperature;  
**Output:** motor for making the fan, servo, light.

#### Idea 2 Women's Voices– from Yufei
We are also very interested in feminist related topics. As the female voice is often ignored, we would like to make a installation where the male eyes and ears close when a female voice is heard. Possibly making a face mask two ear muffs and controlling their opening and closing using several servos.  
  
**Input:** distance measurement, sound sensor; 
**output:** servos.  
  
However, the idea was abandoned in view of the difficulty of distinguishing whether the sound sensor was a female voice or not.

#### Idea 3
During the discussion, we thought that the relationship between two people was something to think about and would also bring more variation to the piece. It occurred to us that the breath and temperature of two people could be shared to feed a plant, but considering that the change in the plant might not be obvious, we gave up this idea.  
**Input:** CO2 sensor, temperature sensor; 
**Output:** oxygen and water.

#### Idea 4
At this time we are interested in human breathing, which we see as the emotional embodiment of silence. In life we rarely pay attention to breathing, but a person's breathing is a certain reflection of the state he/she is in. When two people breathe at the same rate, are they able to approach each other's state of being, perceive each other's thoughts, or even share the same mind?
Considering that changes in feeding plants may not be visibly observable, we intended to look for other forms.   
We came up with Marina Abramović's The Artist Is Present: March - May 2010, a work whose form and the human relationships it discusses were of interest to us. We thought that when words are ignored, perhaps breathing can embody the interpersonal state.
We hoped that the work would encourage the participants to breathe in the same frequency, so we intended to set up a factor that would interfere when the pair did not breathe in the same frequency, and we came up with the idea of noise.

#### Final Proposal - Breathe Like You
https://docs.google.com/presentation/d/1omDfadEUTZ2S464tUnFpo7NIe_2jQXh4KxJjt8lTMqY/edit#slide=id.g17d7db4cf54_3_0
We decided to build a device that uses barometric and infrared sensors to calculate the participants' breathing rate and reflect it in the brightness of the lamp. The greater the difference between their breathing rates, the stronger the sound of the noise from the DC motor vibrations, prompting the pair to approach each other's breathing rates. The noise disappears when the pair breathes at the same frequency.  
  
  
<img width="800" alt="image" src="https://user-images.githubusercontent.com/119874724/206567113-87605a9d-00c8-475e-b427-b40675dd6549.png">
  
On 4 November we presented the proposal in class and Phoenix suggested that we test whether the air pressure sensor would work as we thought it would.

<h3 id="43">Week 6</h3>
We bought two bmp180 air pressure sensors, two led rings, two PIR sensors from Amazon.  
  
  
<img width="380" alt="image" src="https://user-images.githubusercontent.com/119874724/206531756-cdf7025f-a3c6-41b6-90df-6ab85905688b.png">

We soldered the existing sensors after the delivery arrived.  
  
  
<img width="380" alt="image" src="https://user-images.githubusercontent.com/119874724/206529906-434ef63d-ec5f-4d73-9366-e96a2e5425f7.png">

When writing the code we found that each BMP180 needed a separate I2C code bus. We could not simply connect two sensors at the same time or switch between them, as that would block the I2C bus. It also has only one, unchangeable address.  
After doing some research 📒, we found that we could connect multiple BMP280s on the Arduino Uno via SPI, so we placed a new order for the BMP280.  
At this point, the code was initially completed.  
```
 if(cnt >= 10000)
   {
     analogWrite(MOTORPIN, 0);    
   }
   else
   {
     if(speed <= 240)
     {
       speed += 15;
     }
     analogWrite(MOTORPIN, speed); 
   }
```

<h3 id="44">Week 7</h3>
We designed the rough framework of the installation, which was to attach the air pressure sensor and PIR sensor to the horn, fix the horn to the shelf and make the stand for the installation out of PVC pipe. The installation will start working when the audience walks in.  
At the same time we would like to design a proper housing for the LED light rings.   
Option one would be to 3d print the lampshade and option two would be to fold the lampshade out of paper.  
Option one for the noise part is to use a wire tied to a DC motor. The wire makes noise by striking an object as it turns. The object material could be a plastic bag, a paper bag or a glass bottle, but of course this would need to be tested again. Option two is to make noise using the loudspeaker that we learnt about in week 6 of the lesson.
  
On Wednesday we downloaded 3d models of a lamp and a speaker and booked an intuction of 3d printing.  
  
  
<img width="680" alt="image" src="https://user-images.githubusercontent.com/119874724/206532451-beabc1e3-64a1-41b8-8e70-88c033dda457.png">

On Saturday we went to the 4d model shop in East London to buy the PVC pipes we needed, which did not look very good though. So instead we bought two microphone stands on Amazon that could be retracted in length. We also bought two funnels as plan B for the speakers in the shop, as well as blu tack and some wire.  
  
  
<img width="360" alt="image" src="https://user-images.githubusercontent.com/119874724/206552181-4eaadd65-0c4f-4f9a-9506-7c956b548a34.png">
  
We then soldered the newly arrived bme 280 sensor, but found that the arduino did not recognise it when connected.   
  
  
<img width="370" alt="image" src="https://user-images.githubusercontent.com/119874724/206555971-d3ac82d8-139a-42b7-8f3b-35b7f6a29221.png">  

After searching we found that it was probably because the sensor needed to be connected to 3.3V, but we had accidentally connected 5V. We thought the sensor might have been damaged and bought two more bme 280 sensors from Amazon.  


<img width="400" alt="image" src="https://user-images.githubusercontent.com/119874724/206556190-c95420b7-ca2d-4bb0-b211-12b94c9c6d53.png">

<h3 id="45">Week 8</h3>
A week of experimenting with 3d printing.  
We spent almost five days printing two lampshades. At first we used the mini printer, which failed three times.   
  
  
<img width="360" alt="image" src="https://user-images.githubusercontent.com/119874724/206556464-bbd9d28e-be7b-4e29-aeeb-0c17672b2a01.png">  

Then we switched to a pursa i3 machine. We wanted to use white filament, but the white filament we had in the 3d  printing workshop was old and not sticky enough. So we switched to transparent filament and finally the two lampshades were printed successfully.  
  

<img width="380" alt="image" src="https://user-images.githubusercontent.com/119874724/206556545-d9bc0618-2dc9-4f48-a600-e78c46a6dac0.png">  

After connecting the new Bmp280 sensor, the arduino still gave us the error "I2C not found".   
Peter suggested we try the Grove EMG detector. But if we used it we would need to attach it to the body, the thermal imaging sensor would be pointless and we would be missing an input, so we started looking for other sensors that could indicate breathing.   
  
  
<img width="390" alt="image" src="https://user-images.githubusercontent.com/119874724/206556802-de7728bf-4fce-4f06-ab21-779e04cdd431.png">

We found two sound-related sensors on the 5th floor in Camberwell, the analog sound sensor (volume recognition) and the speech sensor (voice recognition). After experimenting with the analog sound sensor, it was able to measure the breathing rate very well, so we modified the code to use this sensor instead.   
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206557478-36854944-8fea-41f9-a242-bb3778bd4d51.png">  
  
  
```
pressureA = analogRead(0);
Serial.print("pressureA:");
Serial.println(pressureA);

pressureB = analogRead(1);
Serial.print("pressureB:");
Serial.println(pressureB);
```

After deciding on the sensors to use, we tested the code.   
The two inputs and the light were recognised, but neither of them worked consistently. After careful error checking we were still unable to solve the problem 👀, so we made an appointment for a tutorial next Monday.  
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206557988-491b67c7-1d78-4718-9412-258f956118e5.png">

The first horn failed 4 times in 3d printing and we continued to try to print.  
  
  <img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206558183-080b4935-b4cc-4a8e-bff7-28acf7aee77d.png">

<h3 id="46">Week 9</h3>  

#### Monday  
Our first horn printed successfully on Monday!!🎉
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206559174-d6ae234c-368a-436b-967b-6fd09b9dfc97.png">

When we tested the code we found that the values shown in the monitor did not work in a loop and sometimes even stopped completely.  
Peter suggested that we comment out some code and print out our data in the serial monitor to test what was wrong. We found that the PIR sensor and sound sensor were fine, but the led ring was always on when the print light was off, which did not match our assumption that the light would flicker as people breathed, and we finally concluded that the problem was with the LED rings.  
Matt helped us to call the example in libraries to test it and found that the LED was working fine. So we modified the code to write the function of the LED into loop, adding pixel.clear(); pixel.show(); . The light then worked properly. ✌️  
  
Then we started testing the DC motor and we found that it was not very easy to get two people to breathe at the same frequency. So we experimented a great deal and modified the set thresholds so that when two people breathed at the same frequency for three loops, the noise diminished. After a day of modifications, our installation was finally working as envisaged.   

#### Tuesday  
We found that when the two were breathing at the same frequency, the DC motor would not stop to make the noise disappear.   
Peter told us that our resistors, transistors and other components were too close together and could be easily shorted, and that we could spread the resistors and other components out a bit to prevent accidental touching.   
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206560249-5002d851-3232-49b1-b24a-355679eaf352.png">  

But after we reconnected them, the motor still wouldn't stop. So we considered using a servo instead of a DC motor. After the change to a servo, the installation was able to run successfully.  
  
<img width="402" alt="image" src="https://user-images.githubusercontent.com/119874724/206560488-216607d2-ac60-451e-bcd3-12cb092c6bde.png">

  
```
if(cnt >= 3)
{
  delay(5000);
  cnt =0 ;
}

else if(cnt < 3)
{
  for(pos = 0; pos <= 180; pos++)
  {
    myservoA.write(pos);
    myservoB.write(pos);
    delay(5);
  }
}
```
  
We were going to solder the wires to the cavity board. As our two PIR sensors and two sound sensors need to be glued to the speaker of the shelf, we need to leave about 2m of wire connected to the arduino. And since each sensor has three connections, we soldered twelve 2m wires and planned to continue soldering the rest tomorrow.  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206561106-5f91ef75-0f48-4e53-b806-3ff87a9cabd3.png">

#### Wednesday  
We started printing the second horn and it failed about 5 times.  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206561504-00addab1-6be0-4821-b655-2975cf217aba.png">
We soldered all the wires, but the arduino indicator did not light up when connected to the arduino. After modifying the soldering method, the code could be uploaded and run, but only one PIR sensor worked properly. So we sorted through the wires again and found that some of the wires were soldered incorrectly.  
  
#### Thursday  
When the horn was almost finished printing, the filament was used up, so we had another print failure. As there was no more black filament in the studio that we wanted, we decided to hold off on printing for the time being.  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206562160-913735be-8c36-4908-9904-1c95b50039fe.png">


After we finished modifying the wires, it still didn't light up when connected to the arduino, yet it would light up when unplugged. After consulting the instructor, we found that the circuit was shorted out. After cleaning up the excess solder, the circuit finally worked properly. But the value of one of the sound sensors kept getting very high and we checked the wires and found no problem.  
  
  
<img width="393" alt="image" src="https://user-images.githubusercontent.com/119874724/206562524-359131d9-0b07-4b55-92aa-658571e66d33.png">

Lexin helped us find a new black filament, so we started printing the second horn again（Might be the sixth time? 😭）

#### Friday  
The second horn was printed successfully.  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206562741-d158fb63-4243-424b-bb89-f49d67e83636.png">

After assembling the components we showed our work to phoenix in class. However, one of the solders on one of the LED rings broke and one of the sound sensors still had a extreme high value. So basically only half of the installation was working. Phoenix suggested we change the servo to another form, so we planned to use speakers to make noise instead.  
  

<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206562941-726e8da8-13cf-48ce-9bd8-2eb5c9701efa.png">
  
In addition we plan to laser cut an acrylic box to hide the arduino board, the strip board and the mess of wires.


<h3 id="47">Week 10</h3>  
We first tested it with cardboard and then laser cut an acrylic box to fit the arduino and wires into:
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206563077-504a28c9-1ad9-4dea-902d-a61746a64c9e.png">  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206563427-fccbe3fb-8c7e-40dc-a5c9-e666ccc1327c.png">

We removed the two servos and replaced them with a speaker as suggested by Phoenix, modified the code and it worked fine.  
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206563138-52e51eb3-cf15-4bd9-aac9-ee64e6a8fbb4.png">  

```
if (cnt >= 3)
{
 tone(BUZZER, 0);
 delay(5000);
 cnt=0;
}
else if(cnt<3)
{
 digitalWrite(BUZZER,HIGH);
 tone(BUZZER, 1000);
 delay(100);          
}        
```  

On Wednesday we assembled the installation and shot a video showing the work.
Done! Ta-da! 🥳🥳🥳  
  
  
<img width="416" alt="image" src="https://user-images.githubusercontent.com/119874724/206574874-f817ef95-e61b-493b-b3b3-09e3b5342ba8.png">


<h2 id="48">Reference</h2>  
  1.https://www.thingiverse.com/  
    
  2.https://www.zimoun.net/  
    
  3.https://www.blog.berrybase.de/blog/2020/11/09/neopixel-ring-mit-arduino-ansteuern-so-wirds-gemacht/  
    
  4.https://blog.csdn.net/qq_20553613/article/details/104833495  
    
  5.https://github.com/sparkfun/BMP180_Breakout/issues/2  
    
  6.http://cactus.io/hookups/sensors/barometric/bme280/hookup-arduino-to-multiple-bme280-barometric-pressure-sensors  
  
  7.https://www.youtube.com/watch?v=i_1yAJnbR9U  
    
  8.https://wiki.dfrobot.com/Analog_Sound_Sensor_SKU__DFR0034  
  
  9.https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm  
  
  10.https://create.arduino.cc/projecthub/Rad_Silviu/speaker-with-arduino-be454c  
  
  












