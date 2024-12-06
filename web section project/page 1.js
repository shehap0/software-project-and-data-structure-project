const images = [
    "photo/welcome 1.jpg", "photo/welcome 3.jpg",  "photo/welcome 5.jpg", "photo/welcome 8.jpg", "photo/welcome 9.jpg",
    "photo/welcome 10.jpg", "photo/welcome 11.jpg",
    "photo/welcome 13.jpg", "photo/welcome 15.jpg", 
    "photo/welcome 16.jpg"
  ];
  
  const texts = [
    "the pyramids - Egypt",
    "portfine - italy",
    "New York city - USA",
    "Venice - italy",
    "Mount Fuji - japan",
    "Sakura Temple - japan",
    "Magome - japan",
    "Tokyo - japan",
    "New York city",
    "Valley of Kings - Egypt",
  ];
  
  let currentIndex = 0;
  
  function showImage(index) {
    const imageElement = document.querySelector(".image-container img");
    const overlayTextElement = document.querySelector(".overlay-text");
  
    imageElement.style.opacity = 0; // Start fading out
    setTimeout(() => {
      imageElement.src = images[index];
      overlayTextElement.textContent = texts[index]; // Update overlay text
      imageElement.style.opacity = 1; // Fade back in
    }, 300); // Matches the CSS transition duration
  }
  
  function showPreviousImage() {
    currentIndex = (currentIndex - 1 + images.length) % images.length;
    showImage(currentIndex);
  }
  
  function showNextImage() {
    currentIndex = (currentIndex + 1) % images.length;
    showImage(currentIndex);
  }
  