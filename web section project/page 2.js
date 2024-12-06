const images = ["photo/intro 1.jpg", "photo/intro 2.jpg", "photo/intro 3.jpg", "photo/intro 4.jpg", "photo/intro 5.jpg"]; 
let currentIndex = 0;

function showPreviousImage() {
  currentIndex = (currentIndex - 1 + images.length) % images.length;
  document.querySelector(".image-container img").src = images[currentIndex];
}

function showNextImage() {
  currentIndex = (currentIndex + 1) % images.length;
  document.querySelector(".image-container img").src = images[currentIndex];
}
