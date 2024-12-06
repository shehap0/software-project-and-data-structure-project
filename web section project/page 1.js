// Define an array of background colors or images
const backgrounds = [
    "lightblue",
    "lightgreen",
    "lightcoral",
    "url('https://via.placeholder.com/300x200')", // Example image
    "url('https://via.placeholder.com/300x200/ffcc00')"
];

let currentIndex = 0;

// Get elements
const backgroundBox = document.getElementById("background-box");
const prevArrow = document.getElementById("prev-arrow");
const nextArrow = document.getElementById("next-arrow");

// Function to update the background
function updateBackground() {
    const currentBackground = backgrounds[currentIndex];
    if (currentBackground.startsWith("url")) {
        backgroundBox.style.backgroundImage = currentBackground;
        backgroundBox.style.backgroundSize = "cover";
        backgroundBox.style.backgroundPosition = "center";
    } else {
        backgroundBox.style.backgroundImage = "none";
        backgroundBox.style.backgroundColor = currentBackground;
    }
}

// Event listeners for arrows
prevArrow.addEventListener("click", () => {
    currentIndex = (currentIndex - 1 + backgrounds.length) % backgrounds.length;
    updateBackground();
});

nextArrow.addEventListener("click", () => {
    currentIndex = (currentIndex + 1) % backgrounds.length;
    updateBackground();
});

// Initialize the first background
updateBackground();
