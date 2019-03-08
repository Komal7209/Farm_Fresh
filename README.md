# Farm_Fresh
# Synopsis
Goal-Revolutionary Website which not only facilitate direct contact between end user and producer but also with details with indications of time left for consumption of that edible. It’s for promoting the kitchen farming and business management for farmers.
Prototype and technologies used:
1. Front end: working with HTML,CSS,Javascript,bootstrap
2.Django: as backend
3.Setting up final website
4. Hardware implementation for provision of raw data using Arduino Programming and Sensors for calculating freshness and expiry date and side by side communicating with Django server to update changes

# Aim(s)
1. To facilitate farmers and users to get a fair price by cutting out the middle man.
2. Support locals by giving them provisions for selling their own fruits and vegetables and supporting kitchen gardening.
3. Promoting usage of organic products.
4. Using applications of IoT to get the estimated quality of fruits and vegetables during shipping.

# Technologies Used
1. Arduino AtMega 328
2. NodeMCU esp8266 based development board
3. Arduino IDE
4. Esp8266 AT firmware
5. Django
6. HTML 5
7. CSS 3
8. Bootstrap 3
9. Java Script

# Working
The project focuses on empowering the farmers as well as providing passive income to the society.
Above goal is achieved by provision of direct selling between farmer and end user thus providing maximum profit to farmers as well as fair price to end users. 
Apart from providing direct contact the service also provides the information regarding the fruits and vegetables which are being purchased.
The service manages this by providing the customer with the count of days since the vegetables or fruits were cultivated. Upon ordering the site also provides with an approximate best before date for the products. This is done by taking sensor reading while the products are being shipped. This data is calculated on the basis of the amount of Ethanol Gas (in ppm), humidity and temperature (in °C) in which the product was shipped.
This service will also provide an option for the small-scale producer to sell their own produce in order to generate a passive income.

# Data flow
The process starts when the farmer adds the amount of available produce.
User places the order as per his/her own requirements.
The order is forwarded to the farmer who prepares for the shipping of the produce after packaging and requesting for delivery.
The delivery agent arrives at the farmer's address and receives the goods.
While the product reaches the customer's home with the sensors placed in the shipping container of the delivery agent takes the reading and transmits them to the application server.
This data includes the raw information of the sensor readings taken from DHT-11 ang MQ-3 sensor.
This data is then provided to the customer after the processing is done.

# Add-ons to be made in future
1. An algorithm to make sure that the farmer's produce is sold before it gets rots out. A review-based system to make sure that proper quality is maintained.
2. Add a private key method to identify distinct sensors to make sure that the sensor data is correctly identified and linked to the particular user's order.
3. Better local discovery to make sure that the nearby farmers are preferred over those far off to make sure that the order reaches in optimal time.
