**Resources**
- Slides: [Slides.com](https://slides.com/rumansaleem/foundation)
- Notes: [NotionHQ](https://www.notion.so/rumansaleempersonal/Web-Development-Building-up-the-Foundation-f12b9d0472cf47aaa33494c40b2a95ad) (Same as the content below)

---

# Web Development: Building up the Foundation

**How do you access a website?**

- Open Web browser
- Enter URL
- Browser fetches data from the server.
- Browser renders the response received from server.
- User interacts with the rendered webpage, using link, forms, buttons, custom components.

**What does a URL look like?**

URL: `https://google.com/search?q=hello+there`

### Components of a URL
- Protocols: `http` & `https` (in context of accessing web through browsers)
- Host: Domain/IP `google.com`
- Port: In this case implicit, default https port `443`
- URI (path): Uniform Resource Identifier, identifies the resource on an application.
- Query String: Request Parameters

### What happens when you enter a URL in the browser?
When we enter `https://google.com/search?q=hello+there`  URL in the browser, following events happen in sequence.

- Browser makes a HTTP request `GET /search` to `[google.com](https://google.com)`
    - A DNS lookup is performed for `[google.com](https://google.com)` and it resolves to the IP `172.217.166.14`.
    - `172.217.166.14` corresponds to a physical server machine on the internet.
    - Also, this request is made with HTTP protocol, which means by default, request is made on port number `443` unless explicitly specified in the URL.
    - Web Server listening on port `443` receives the request.
- On Receiving a HTTP Request, Web Server performs the desired action by the request and returns a response accordingly.
- Browser renders the HTML sent by the server on the screen.
- As a part of rendering HTML, browser makes some extra HTTP requests, to load the assets (images, scripts, stylesheets, fonts etc.)

### DNS Resolution

Resource to know about DNS in detail: [https://howdns.works](https://howdns.works).

## Role of a Web Server

A Web Server is an Application process that keeps running on a machine. This process handles the incoming HTTP requests and send HTTP responses back to the client. 

- A config defines the document root of the server. This document root is the path to a directory in the system from where web server serves the files.

    **Example:** Suppose document root is set to `/var/www/html`. 

    - web server receives a request to the path `/contact.html` , the web server looks for a file `/var/www/html/contact.html` within the system. If it doesn't find a file it gives a 404 error, otherwise serves the file.
    - web server can be configured to pass on the request to other programs which handles the request dynamically and send the response back to the web server. Web server returns the same response back to the client.
    - **CGI:** Common Gateway Interface, is the specification by w3c, which acts as a interface between a CLI application and web server. To allow dynamic render of the HTML.

## Role of a web browser

- makes  GET, POST HTTP requests to the server.
- handles the responses.
- renders HTML and applies the stylesheet.
- loads the scripts and starts execution of the scripts in a linear fashion.
- provides APIs to interact with the HTML page, make AJAX calls, access resources etc.

## Languages and Frameworks

|Format     | Meaning                |
|-----------|------------------------|
| *italics* | Recommended            |
| **bold**  | My personal preference |

> #### Note
> This is NOT a list all of the web frameworks, many frameworks might be missing out. This is the list of popular frameworks that I know of, with recommendations and my personal choices.

### Server Side 

- PHP: *CodeIgniter*, ***Laravel***, *Symfony*, CakePHP, Yii, Slime, Zend Framework, etc
- JavaScript (Node.js): ***ExpressJS***, Meteor.js, Hapi.js, AdonisJS, SailsJS etc.
- Ruby: ***Ruby on Rails***
- Java: *Spring*, Hibernate, Apache Struts
- Python: *Flask*, Django
- GoLang: Revel

### Client Side

- JavaScript: *React*, ***Vue.js***, Angular, **Svelte**, **AlpineJS**, Ember.js, backbone.js, jQuery, etc.
- CSS: *Bootstrap*, *Bulma,* Materialize, Foundation, SemanticUI,  ***TailwindCSS***, etc.