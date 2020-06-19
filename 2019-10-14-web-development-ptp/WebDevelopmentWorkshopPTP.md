## Workshop Notes

[GitHub Repository](https://github.com/rumansaleem/php-mvc-demo)  
[Session Slides](https://slides.com/rumansaleem/web-dev)

### `1f770a5` posts: view all posts from database

- We have a traditoional PHP app served from `public` directory.
- Our website has three pages for now.
  - Home page: lists all the posts from database
  - About page: about page shows random about page
  - Contact page: contact page shows contac details
- We use a seperate file to initialise database connection and use it only where required.
- We have also seperated the database credentials to seprate config file.
- Seperate config file helps other people to easily configure database credentials according to their own database, without messing up with actual code.
- We add this config to `.gitignore` which serves two purposes:
  - it changes from person to person so no need to version control it.
  - it contains secret database credentials which should not be public on GitHub.

### `c83ac44` refactor: extract common view areas to partials

- We have the same HTML structure header, footer in all three pages.
- We have refactored the common HTML header and footer into seperate partials. It has two advantages:
  - We do not need to rewrite the same HTML file again and again for new pages. 
  - When we add new links to the header, we only need to update in one single file.

### `7993cee` auth: login, logout, signup

- We need to add users to our blog
- We have implemented basic signup and login without any validations.
- Signup:
  - A single signup.php file checks request method, if its post request it tries to create a new user in database, else it serves the page with signup form.
  - When it's a POST request we create the user in the database and login the createdt user by storing his Id in the session.
  - We use php's `password_hash` function to hash their password before storing into database. It uses blowfish algorithm to hash the password. By default it uses 10 rounds of Blowfish algorithm.
  
- Login:
  - As we did for signup, we do the same for login. If it's a POST request we try to login user expecting credentials as POST parameters, else we serve the page with login form.
  - If it's a POST request we retrive the user by their email.
  - Then we match the given password with hashed password stored in database, using php's `password_verify` function.
  - If the password matches we login user by adding his id in the session against the key `auth`.
- We conditionally render login/signup links or logout link depending on wether the user is logged in or not.
- We check if Session has the key `auth` set, if its set, user must have been logged in, if its not then user is not logged in.

### `de5082a` posts: logged in user creates posts
- We added a create post form to our home page.
- We conditionally show create post form or login message depending on wether user has logged in or not.
- The create post form submits a POST request to the `posts/store.php` script, which saves the post in database and redirects back to home page.
- We check if the user is not logged in we redirect back to home without creating the post. If he is logged in we use his Id from session to assign him as the author of the post.

### `598511f` refactor: seperate bootstrapping logic and helper functions

- We have been performing several bootstrapping tasks in the head partial, like:
  - turn on error reporting
  - starting/resuming session
  - making database connection 
  - loading helper functions
- We refactor to seperate out these tasks to a seprate file `bootstrap.php`.
- We use this bootstrap file in every file instead of including the whole header partial even if it is not required.
  
### `94c17c7` refactor: basic if-else routing to controllers
- We would be following MVC architecture, it time to sperate out the controllers, views and models.
- We build a router to route requests to our controllers.
- All the requests hit our entry point `index.php`.
- Depending on the request uri and http verb (request method) our routing logic forwards the request to desired controllers.
- Each Controller is responsible for independent functionalities.

> we still have views inside the controllers we would seperate them out in the next step.


### `0d5a43e` refactor: extract views out from controllers

- We seperate out views from controllers, and give them names with a prefix `*.view.php`, so that we can tell by name of file, that it is a *view*.
- We only require the desired view when view is to be rendered from controller.
  

### 2a2463e refactor: use view helper function to load views
- We make a helper function to load views with data from a controller.
- This makes code more readable.
- We do not need to take care of the relative path to the views.

### `6f02997` refactor: use redirect helper function to redirect.
- We make helper function to redirect users to different pages.
- Again, it makes code more readable.

### `a36c989` refactor: clean up if-else routing
- Currently, we have used if-else ladder to check for every possible uri and route requests to controller.
- We refactor the logic to use a simple associative array of mappings, which maps the uri to controllers.

### 1d4e3a5 refactor: use controller classes
- Our controller are now clean, but they are still plain php scripts.
- Its time to extract into classes.
- We also group two sperate controller dealing wth same logic to different methods of the same class.
- Now, we route the request to a Controller's method. instantiate the controller and invoke the method mapped to uri.

### `71b0b39` refactor: push controller contructor to parent class

- We are injecting database instance to every controller, through contructor.
- We can extract this common functionality to a parent class.
- We do not need to always add database instance through controller whenever we make new controller.
- In future if we need to add more dependencies we can just add them to parent class, which every controller extends.

### `86b8a2a` refactor: use database class, extend PDO
- We have been using mysqli api to make connection with MySQL.
- Let's take a look at PDO:
  - It can be used for all SQL databases.
  - It has a nice object-oriented API
  - It supports named-parameters
- We extend PDO to write some custom Database to simplify execution of SQL queries using prepared statements.
- Database uses the singleton pattern, it has only one instance created.
- It requires database configuration to be initialised.

### `c135672` refactor: move routes to seperate file
- We move static routes array to a seperate file.
- In our entry point, we only load this array of routes and handle the request.

### `39802b5` refactor: use Router class
- We still have the request handling logic inside entry point.
- Lets encapsulate this into a Router class.
- Router has a nice api to register new routes instead of exposing a simple array.
- Router handles the request and route it to specific controller.

### `9d9c580` refactor: use Request class

- Encapsulate request method, uri, parameters etc to a Request class.
- Request class is created from super globals
- Request object can now be passed to router  which handles the request based on uri and method.
- Request is also injected to every controller method, that may need to access request parameters and other request related data.


### `26ff6d5` refactor: move core classes to core directory
- We have all classe that form the core of our applciation in the app folder.
- We group them altogether in a Core directory.

### `10f8d2d` refactor: use QueryBuilder class
- We have made a query builder to abstract the SQL layer from controllers.
- Currently, Controllers know about SQL and how to query the data from database.
- We add this layer of abstraction between controller and database.
- Query builder gives us a fluent API, we do not need to care about SQL.
- More on details later.

### `8ccebd0` refactor: use Auth class with static helpers
- Encapualate the authentication logic and all autencication related helpers in the Auth class with static methods.
  
### `5a56b2f` autoload: use classmap autoloader
- We are loading each and every file we create in the entry point.
- Now, we autoload all of these classes using composer's autoloader.
  
### `6be72a6` autoload: use namespaces, use psr-4 autoloading
- We switch to namespacing and psr-4 autoloading standard.
- PSR-4 standard needs only root namespace and from root it follows the file structure for namespacing and the autloader loads all classes in the root namespace.
  
### `5d5322d` use application container class
- We need a dependency injection container.
- We bind the instances to application container.
- Application knows how to instantiate the dependency.
- No other part of our application is concerned about instantiating a class.
- It asks the application container for the instance.

### `37b2f01` config: add readme, use migrations
- For a new person its hard to get the database structure.
- Migrations are the solution.
- New developer will run the migrations and it will setup all the tables in the database, required for the application to run properly.
