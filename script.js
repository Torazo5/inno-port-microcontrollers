document.addEventListener("DOMContentLoaded", function () {
  // Add an event listener to the window object that will call the scrollFunction whenever the user scrolls
  window.addEventListener("scroll", scrollFunction);

  function scrollFunction() {
    // Get the current scroll position
    var scrollPosition = window.scrollY;

    // Get the navbar element
    var navbar = document.querySelector(".navbar");

    // Check if the scroll position is greater than 200 pixels
    if (scrollPosition > 200) {
      // If it is, add the "scrolled-past-pixels" class to the navbar
      navbar.classList.add("scrolled-past-pixels");
    } else {
      // If it's not, remove the "scrolled-past-pixels" class from the navbar
      navbar.classList.remove("scrolled-past-pixels");
    }
  }
});

