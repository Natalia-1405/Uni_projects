document.addEventListener("DOMContentLoaded", () => 
{

    const form = document.querySelector("#addGem");
    const info = document.querySelector("#info");

    form.addEventListener('submit', (e)=>
    { 
        const send = new FormData(form); 
        const xhr = new XMLHttpRequest(); 
        xhr.open("POST","http://localhost/projekt/PHP/sendGembase.php",true);

        xhr.onload = function() 
        {
            if(xhr.responseText === "Dodano") 
            {
                info.style.color = "green";
                info.innerHTML = "Gem added!";
                form.reset();
            } 
            else 
            {
                info.style.color = "red";
                info.innerHTML = "Gem not added: " + xhr.responseText;
            }
        };

        xhr.send(send);
        e.preventDefault();
    });
});