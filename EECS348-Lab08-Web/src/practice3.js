////////////////////////////////////////////////////////////////////////////////

let password = document.getElementById("password"),
    confirm  = document.getElementById("confirm-password"),
    validate = document.getElementById("validate")

validate.addEventListener("click", () => {
    if (password.value.length < 8) {
        alert("First password is less than 8 letters.")
        return
    }

    if (confirm.value.length < 8) {
        alert("Second password is less than 8 letters.")
        return
    }

    if (password.value != confirm.value) {
        alert("Two passwords don't match.")
        return
    }

    alert("Everything looks good!")
})

////////////////////////////////////////////////////////////////////////////////
