////////////////////////////////////////////////////////////////////////////////

function $(query) {
    return document.querySelector(query)
}

function toColor(rgb) {
    return `rgb(${Object.values(rgb).join()})`
}

function clamp(value, min, max) {
    if (value < min) return min
    if (value > max) return max
    return value
};

function updateParagraph(attribute, value) {
    let target = document.querySelector("#target > p")
    target.style[attribute] = value
}

let borderColor     = {r: 0, g: 0, b: 0},
    backgroundColor = {r: 0, g: 0, b: 0}

////////////////////////////////////////////////////////////////////////////////

// Border Color Controls
let border = Object.entries({
    "border-r": 'r',
    "border-g": 'g',
    "border-b": 'b'
}).forEach(el => {
    $(`#${el[0]}`).addEventListener("input", e => {
        e.target.value = clamp(e.target.value, 0, 255)
        borderColor[el[1]] = e.target.value
        updateParagraph("border-color", toColor(borderColor))
    })
})

////////////////////////////////////////////////////////////////////////////////

// Background Color Controls
let background = Object.entries({
    "background-r": 'r',
    "background-g": 'g',
    "background-b": 'b'
}).forEach(el => {
    $(`#${el[0]}`).addEventListener("input", e => {
        e.target.value = clamp(e.target.value, 0, 255)
        backgroundColor[el[1]] = e.target.value
        updateParagraph("background-color", toColor(backgroundColor))
    })
})

////////////////////////////////////////////////////////////////////////////////

$("#border-w").addEventListener("input", e => {
    e.target.value = clamp(e.target.value, 0, 30)
    updateParagraph("border-width", e.target.value + 'px')
})

////////////////////////////////////////////////////////////////////////////////