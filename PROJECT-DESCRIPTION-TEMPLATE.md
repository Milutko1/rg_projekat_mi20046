# Kosarkaska lopta

mi20046 - Milutin Nikodijevic

Scena prikazuje teksturisanu kosarkasku loptu na drvenom podu.
Lopta je osvetljena directional i point svetlom.
Jacina point svetla podesava se preko grafickog korisnickog interfejsa.
Pritiskom na Space pokrece se niz dogadjaja: nakon cekanja lopta
skace, a zatim prestaje da skace i pocinje da se rotira.

## Controls

- Space -> Pokretanje ili ponovno pokretanje niza dogadjaja.
- Klizac "Point jacina" -> Podesavanje jacine point svetla od 0 do 2.

## Features

### Fundamental:

- [x] Model with lighting
    - Teksturisana lopta sa ambijentalnom, difuznom i spekularnom komponentom osvetljenja.
    - Pod se iscrtava jednobojno i takodje je osvetljen.

- [ ] Two types of lighting with customizable colors and movement through GUI or ACTIONS
    - Implementirani su directional i point svetlo.
    - Point svetlo ima slabljenje sa rastojanjem.
    - Preko GUI-ja podesava se jacina point svetla.
    - Boje i polozaji svetala nisu podesivi preko GUI-ja ili akcija.

- [x] ACTION -> AFTER_M_SECONDS -> EVENT_A -> AFTER_N_SECONDS -> EVENT_B
    - ACTION: pritisak tastera Space.
    - Nakon 1 sekunde pocinje skakanje lopte.
    - Nakon naredne 4 sekunde skakanje se zavrsava i pocinje rotacija oko Y ose.
    - Rotacija traje do ponovnog pokretanja niza ili zatvaranja aplikacije.

### Group A:

- [ ] Frame-buffers with post-processing
- [ ] Off-screen Anti-Aliasing
- [ ] Parallax Mapping
- [ ] Bloom with the use of HDR

### Group B:

- [ ] Deferred Shading
- [ ] Point Shadows
- [ ] SSAO

### Engine improvement:

Nisu dodavane nove engine funkcionalnosti.

## Models:

- [Basketball](https://poly.pizza/m/eopD_12UuB8)
    - Autor naveden na stranici: Poly by Google.
    - Licenca: Creative Commons Attribution (CC BY).

- [Wood Floor](https://poly.pizza/m/4qpvnIQNcl5)
    - Autor: Mark Steelman.
    - Licenca: Creative Commons Attribution (CC BY).
    - U sceni se koristi jedna smedja boja za ceo model poda.

## Textures

- CHAHIN_BASKETBALL_TEXTURE.jpg
    - Tekstura preuzeta uz model Basketball.
    - Izvor: https://poly.pizza/m/eopD_12UuB8
    - Autor naveden na stranici: Poly by Google.
    - Licenca: Creative Commons Attribution (CC BY).

Pod ne koristi teksturu.

## Other resources
