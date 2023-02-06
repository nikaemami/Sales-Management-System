# Sales-Management-System
In this project a virtual buying and selling management system is implemented. In this system, there are two types of users:  1) seller 2) buyer. Each of these two types of users have different powers and will behave differently. 

Description of the project and desired features:


<h2>Registration of a new user:</h2>

At first, every new user who enters the system must register in it. This feature is for both seller and buyer roles. To register a new user, the username, password and role of this user must be entered in the form below. Usernames are unique in each role and it is not allowed to add any user with the same username and the same role.

<h2>Logging into the user account</h2>

If a user with a specific role has already registered in the system, he can log into his user account using the following command. Make sure that a user does not enter the system directly after signing up and must log in to the system. A suitable message is shown to the user after successfully entering the system. If there is no user with the entered information, you should print an appropriate error.

<h2>Logging out of the user account</h2>

To log out of the user account, use the logout command in the form below. Note that the program must still be running after executing the logout command and must not be closed; Because another user may want to enter the system.

<h2>User information observation</h2>

Every user should be able to view their information in the system by entering the view command in the form below. 
This information includes the following: username, user role, account balance amount (will be zero for new users)

If the user was a buyer: all purchases including the name of the product, its unit price, the number purchased from this The product and the name of the seller becomes the product.
If the user is a seller: the list of products that he has put up for sale, which will include the name, unit price and stock for each product.

<h2>Credit increase</h2>

Every buyer user (this possibility is not available for seller users) has the right to add an amount to his account balance.
to add For this, you must specify the desired amount in the form below.

<h2>Adding goods for sale</h2>

A user who is registered as a seller in the system can place his goods for sale in the system. To do this, you must first enter your username in the form below, and then enter the product details, which include the name, unit price, and stock. 

<h2>Observation of the available goods</h2>

Every user should be able to view the information of all products by entering a command in the form below. This information includes the following:
Vendor name، Product name، Product unit price، Product inventory

<h2>Buying goods</h2>

Any user with the role of buyer can buy a product with the following command. In case of a successful purchase, this product must be removed from the list of products in the system (its inventory will be reduced) and added to the buyer's shopping list. Also, the cost of buying goods must be deducted from the buyer's account and transferred to the seller's account.



