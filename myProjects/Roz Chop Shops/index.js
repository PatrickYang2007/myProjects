let items= document.querySelectorAll('.slider .list .item');
let next= document.getElementById('next');
let prev= document.getElementById('prev');
let thumbnails=document.querySelectorAll('.thumbnail .item');

let countItem= items.length;
let itemActive=0;

next.onclick= function(){
    itemActive+=1;
    if(itemActive >= countItem){
        itemActive=0;
    }
    showSlider();
}
prev.onclick=function(){
    itemActive-=1;
    if(itemActive<0){
        itemActive=countItem-1;
    }
    showSlider();
}
function showSlider(){
    let itemActiveOld= document.querySelector('.slider .list .item.active');
    let thumbnailActiveOld= document.querySelector('.thumbnail .item.active');
    itemActiveOld.classList.remove('active');
    thumbnailActiveOld.classList.remove('active');

    items[itemActive].classList.add('active');
    thumbnails[itemActive].classList.add('active');
}

thumbnails.forEach((thumbnail, index) => {
    thumbnail.addEventListener('click', () => {
        itemActive = index;
        showSlider();
    });
});


function scrollToElement(elementSelector, instance = 0) {
    const elements = document.querySelectorAll(elementSelector);
    if (elements.length > instance) {
        elements[instance].scrollIntoView({ behavior: 'smooth' });
    }
}

const linkIds = ["link1", "link2", "link3", "link4", "link5"];

linkIds.forEach((linkId, index) => {
    const link = document.getElementById(linkId);
    if (link) {
        link.addEventListener('click', () => {
            const targetSelector = getTargetSelector(index);
            scrollToElement(targetSelector);
        });
    }
});

function getTargetSelector(index) {
    const targetSelectors = [
        '.top',        // For #link1 - Home
        '.about-me',   // For #link2 - About Me
        '.slider',     // For #link3 - Gallery
        '.book-now',   // For #link4 - Book Now
        '.book-now'    // For #link5 - Book Appointment Now
    ];

    return targetSelectors[index] || '';
}


