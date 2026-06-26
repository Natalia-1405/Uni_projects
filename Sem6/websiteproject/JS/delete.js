document.addEventListener("DOMContentLoaded", () => 
{
    const deleteGem = document.querySelectorAll(".formDelete"); 

    for (let del of deleteGem)
    {
        del.addEventListener('submit', (e) => 
        {
          const data = new FormData(del);
          const xhr = new XMLHttpRequest();
          xhr.open("POST", "http://localhost/projekt/PHP/delete.php", true);
          
          xhr.onload = function() 
          {
            const card = del.closest('.card');
            card.style.transition = "opacity 0.3s";
            card.style.opacity = "0";
            setTimeout(() => card.remove(), 300);
          };
            
          xhr.send(data);
          e.preventDefault();
        });
    }
});