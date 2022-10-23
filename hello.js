/* darkmode */
.darkmode {
  padding: 10px;
  width: 120px;
  height: 60px;
  background: rgb(46, 48, 53);
  border-top-left-radius: 60px;
  right: 0;
  bottom: 0;
  box-shadow: 1px 1px 10px 4px rgba(0, 0, 0, 0.3);
  position: fixed;
  z-index: 999;
}

.darkmode button {
  width: 50px;
  height: 50px;
  border: none;
  margin-top: 6px;
  margin-left: 40px;
  border-radius: 50%;
  background: rgb(37, 39, 43);
  outline: none;
  cursor: pointer;
  display: flex;
  box-shadow: 1px 1px 2px 2px rgba(0, 0, 0, 0.3),
    -2px -2px 2px rgba(255, 255, 255, 0.2);
}

.darkmode button:active {
  box-shadow: 1px 1px 2px 2px rgba(0, 0, 0, 0.3) inset;
}

.darkmode button:active .feather.moon {
  margin-top: 7px;
}

.feather.moon {
  width: 30px;
  height: 30px;
  margin: auto;
  stroke: #f7b801;
}

/* ... */
.feather.sun {
  width: 30px;
  height: 30px;
  margin: auto;
  stroke: rgb(235, 235, 0);
  display: none;
}

/* copyrigt 2020 muhammaderlangga*/
.copyright {
  font-size: 0.8em;
  opacity: 0.2;
  user-select: none;
}

/* ... */

/* !for JavaScript */
body.dark {
  background: rgb(30, 32, 35);
}
.dark{
  background-color: rgb(30, 32, 35);
}

.whitebg {
  box-shadow: 1px 1px 10px 4px rgba(255, 255, 255, 0.2);
  background: #e2e1e1;
}

.whitecr {
  color: #ffffff;
}

.blackcr {
  color: black;
}

.bgdark{
  background: rgb(30, 32, 35);
}

.darkFAQ a{
  color: #ffd100;
}

nav a.whitecr:hover {
  color: rgb(46, 48, 53);
}

.whiteburger {
  background: #fff !important;
}

.darkmode button.wh {
  background: #eeeeee;
  box-shadow: 2px 2px 4px 1px rgba(0, 0, 0, 0.1),
    -2px -1px 2px 1px rgba(255, 255, 255, 0.5);
}

.darkmode button.wh:active {
  box-shadow: 2px 2px 3px 1px rgba(0, 0, 0, 0.1) inset;
}

.darkmode button.wh:active .feather.sun {
  margin-top: 7px;
}

.feather.sun.appear {
  display: inline;
}

.feather.moon.hide {
  display: none;
}

.dark.services-item:hover {
  box-shadow: 0px 5px 25px 4px rgb(246, 183, 1);
}

.dark.card:hover{
  box-shadow: 0px 5px 25px 4px rgba(246, 185, 1, 0.575);
}

.testimonial_dark{
  background-color: rgb(30, 32, 35);
}
.pure_dark{
  background: black;
}
.pure_dark:hover{
  background: black;
}
