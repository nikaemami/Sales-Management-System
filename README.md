# Sales-Management-System
In this project a virtual buying and selling management system is implemented. In this system, there are two types of users:  1) seller 2) buyer. Each of these two types of users have different powers and will behave differently. 

Description of the project and desired features:


<h2>Registration of a new user:</h2>

At first, every new user who enters the system must register in it. This feature is for both seller and buyer roles. To register a new user, the username, password and role of this user must be entered in the form below. Usernames are unique in each role and it is not allowed to add any user with the same username and the same role.


**signup <username> <password> <role>** 
  
**Example: signup person 123 seller**

<h2>Logging into the user account</h2>

If a user with a specific role has already registered in the system, he can log into his user account using the following command. Make sure that a user does not enter the system directly after signing up and must log in to the system. A suitable message is shown to the user after successfully entering the system. If there is no user with the entered information, you should print an appropriate error.

  
**login <username> <password> <role>**

**Example: login otherPerson 231 buyer**

<h2>Logging out of the user account</h2>

To log out of the user account, use the **logout** command. The program must still be running after executing the logout command and must not be closed, because another user may want to enter the system.

<h2>User information observation</h2>

Every user should be able to view their information in the system by entering the view command in the form below. 
This information includes the following: username, user role, account balance amount (will be zero for new users)

If the user was a buyer: all purchases including the name of the product, its unit price, the number purchased from this The product and the name of the seller becomes the product.
If the user is a seller: the list of products that he has put up for sale, which will include the name, unit price and stock for each product.

<h2>Credit increase</h2>

Every buyer user (this possibility is not available for seller users) has the right to add an amount to his account balance.
to add For this, you must specify the desired amount in the form below.

  
**deposit <amount_of_money>**

**Example: deposit 1000**

<h2>Adding goods for sale</h2>

A user who is registered as a seller in the system can place his goods for sale in the system. To do this, you must first enter your username in the form below, and then enter the product details, which include the name, unit price, and stock. 
  

**add_goods <goods_name> <goods_price> <goods_count>**

**Example: add_goods watch 10000 3**

<h2>Observation of the available goods</h2>

Every user should be able to view the information of all products by entering the command **show goods**. This information includes the following:
Vendor name، Product name، Product unit price، Product inventory

<h2>Buying goods</h2>

Any user with the role of buyer can buy a product with the following command. In case of a successful purchase, this product must be removed from the list of products in the system (its inventory will be reduced) and added to the buyer's shopping list. Also, the cost of buying goods must be deducted from the buyer's account and transferred to the seller's account.

  
**buy <goods_name> <goods_count> <seller_username>**

**Example: buy watch 1 thirdPerson**

<h2>Storing information in a file</h2>
All store information, including user and product information, must be stored in one or more files and when running the program, first the previous information is read from the file and then the inputs are received in the command line.

<h2>Delete a product</h2>
A seller of a product can remove his product from the store with the following command. By deleting a product, all information related to it, including the points registered for that product, will be lost. 

  
**remove_goods goods_name**

**Example: remove_goods watch**

<h2>Changing the prices of goods</h2>
A user who is registered as a seller in the system can change the price of goods. To do this, after logging into your user account as a seller, enter the desired command and then the name as follows. Import the product and its new price. If the desired user does not have a product with the entered name, he should encounter an error message.

<h2>Rating the goods</h2>
Each user can rate only once and only to the goods he has purchased. This score must be an integer between 1 and 5.

  
**rate_goods <goods_name> <seller_username> <rating>**

**Example: rate_goods watch third_person 3**

<h2>Deactivation of low-rated goods</h2>
If the average score of a product that belongs to a certain seller becomes less than 2 (while at least 5 buyers have rated that product), that seller can no longer sell the mentioned product and if a customer requests to buy it, the item in question should be considered non-existent.

<h2>Reactivation of goods</h2>
If the average score of a product that has been disabled before becomes greater than or equal to 2 due to the scoring of previous buyers of that product who have not yet registered their score, the product in question will return to normal and until its score is lower again.

<h2>Viewing the available products</h2>
Each user should be able to view the information of all the salable products of the system by entering a command. This information includes the following:
Name of the seller, Name of the product, Unit price of the product, Inventor of the product, Average points of the product

  
**Example: show_goods**

</h2>Searching for goods</h2>
Users can search and view salable goods of the system based on one or more special features. How to enter the command is as follows:
search <number_of_conditions> <goods_attribute> <attribute_value>
Then the number of <number_of_conditions>, pairs of strings of attribute name, and attribute value are entered so that there will be two strings in each line.

  
**Example:**

**search 2** 

**name watch**

**min_price 10000**
