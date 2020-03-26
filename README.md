# Zork huse game
C++ code challenge to create the Zork game  

## The game
You woke up in an attic of a house, you don't remember how did you get there,
but now that doesn't matter. You will have to explore the house and search for a escape
to the outside.  
Some rooms may be closed, so you will have to find the way to open them and see what misteries they hide.  

## How to play
The player can move between rooms using the four cardinal points **(north, south, east, west)** and 
two directions **(up, down)**. Use the map attached in the release to guide yourself through the house.  
The player, also, has three diferent actions **(search, use, drop)** to find or use different objects that he will find in the house.  
**search:** when you search a room you will find one item hided in the room. There could be more than one item per room!  
**use:** you can use the objects you have found to open new rooms. You inventory will show so you can type the item you want to use.  
**drop:** you can drop any object of your inventory in any room of the house, but don't worry, you can pick it up later with **search**.  

*Solution to the game with the fewest movements:* down, west, down, west, search, north, east, up, use, Bedroom_key, 
search, search, west, west, down, south, south, use, Lantern, search, up, north, north, use, Old_key.

## Author
Pablo Manuel Sánchez Trujillo  

## Github repository
https://github.com/PabloSanchezTrujillo/Zork

## License
MIT License  

Copyright (c) 2020 Pablo Sánchez  

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:  

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.  

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.  