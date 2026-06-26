document.addEventListener("DOMContentLoaded", () => 
{

    const formSearch = document.querySelector('#formSearch');
    const inputReset = document.querySelector('#inputReset');

    if(!formSearch) return;

    formSearch.addEventListener('submit', function(e) 
    {

        e.preventDefault();

        const searchName     = document.querySelector('#searchName').value.toLowerCase();
        const cards          = document.querySelectorAll('.card');

        for(let x of cards)
        {
            const name = x.querySelector('h3').textContent.toLowerCase();

            const matchName     = name.includes(searchName);

            if(matchName)
            {
                x.style.display = "";
                x.style.border = "1px solid #e94560";
            }
            else
            {
                x.style.display = "none";
            }
        }
    });

    inputReset.addEventListener('click', function() 
    {
        const cards = document.querySelectorAll('.card');
        for(let x of cards)
        {
            x.style.display = "";
            x.style.border = "1px solid #e94560";
        }
    });

});
