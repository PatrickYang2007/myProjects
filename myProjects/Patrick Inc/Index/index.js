function scrollToElement(elementSelector, instance = 0) {
    const elements = document.querySelectorAll(elementSelector);
    if (elements.length > instance) {
        elements[instance].scrollIntoView({ behavior: 'smooth' });
    }
}

const linkIds = ["link1", "link2", "link3", "link4", "link5", "link6", "link7", "link8"];

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
        '.whoAmI',
        '.Prices',
        '.nonProfits',
        '.Prices',
        '.Prices',
        '.Logo',
        '.footer',
        '.footer'
    ];

    return targetSelectors[index] || '';
}
