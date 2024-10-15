#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXMUSIC 100
#define MAXLEN 20

typedef struct
{
    int min;
    int sec;
} Duration;

typedef struct
{
    char *name;
    char *artist;
    int numArtist;
    char *album;
    char *style;
    int numstyle;
    Duration duration;

} Music;

Music *PlayList;
int NumMusic = 0;

void Menu();                         // mostrar enu;
void OptionMenu(int op);             // mostra opcao escolhida;
void MessageError(int erro);         // dispara mensagens de erro;
int Include();                       // inclui musica;
Music CreateMusic();                 // cria uma musica;
void PrintMusic(Music m);            // mostra musica;
int ValidDuration(int min, int sec); // valida o tempo da musica;
int ListPlaylist();                  // lista todas as musicas;
int Alternate();                     // alterna as playlist;
void SwitchTrack(int track);         // alterna dados na musica

int main()
{
    PlayList = (Music *)malloc(MAXMUSIC * sizeof(Music));
    int op = 1;

    while (op != 5)
    {
        Menu();
        scanf("%i", &op);
        fflush(stdin);
        OptionMenu(op);
        system("pause");
    }

    return 0;
}
void Menu()
{
    system("cls");
    printf("\n - (1) Include music\n");
    printf("\n - (2) Delete song\n");
    printf("\n - (3) Change music\n");
    printf("\n - (4) List music\n");
    printf("\n - (5) Exit\n");
}
void OptionMenu(int op)
{
    int error;
    if (op < 1 || op > 5)
    {
        MessageError(0);
    }
    else if (op < 5)
    {

        if (op == 1)
        {
            error = Include();
        }
        else if (op == 3)
        {
            error = Alternate();
        }
        else if (op == 4)
        {
            error = ListPlaylist();
        }

        if (error <= 0)
        {
            MessageError(error);
        }
    }
}
void MessageError(int error)
{
    switch (error)
    {
    case 0:
        printf("\nError. Invalid option\n");
        break;
    case -1:
        printf("\nError. Maximum number of songs reached.\n");
        break;
    case -2:
        printf("\nError. Empty list.\n");
        break;
    case -5:
        printf("\nError. Enter a valid minute.\n");
        break;
    case -6:
        printf("\nError. Enter a valid second.\n");
        break;
    case -7:
        printf("\nError. Enter a valid minute and second.\n");
        break;
    case -8:
        printf("\nError. Invalid track.\n");
        break;

    default:
        printf("\nError.\n");
        break;
    }
}
int Include()
{
    if (NumMusic >= MAXMUSIC)
    {
        return -1;
    }

    PlayList[NumMusic] = CreateMusic();
    PrintMusic(PlayList[NumMusic++]);

    return 1;
}
Music CreateMusic()
{
    Music m;
    int error = -1;
    m.name = (char *)malloc(MAXLEN * sizeof(char));
    m.artist = (char *)malloc(MAXLEN * sizeof(char));
    m.album = (char *)malloc(MAXLEN * sizeof(char));
    m.style = (char *)malloc(MAXLEN * sizeof(char));

    printf("\nMusic name:\n");
    gets(m.name);
    fflush(stdin);

    printf("\nAlbum:\n");
    gets(m.album);
    fflush(stdin);

    printf("\nArtist:\n");
    gets(m.artist);
    fflush(stdin);

    printf("\nStyle:\n");
    gets(m.style);
    fflush(stdin);

    while (error < 0)
    {
        printf("\nDuracao (MM SS):\n");
        scanf("%i%i", &m.duration.min, &m.duration.sec);
        fflush(stdin);
        error = ValidDuration(m.duration.min, m.duration.sec);
        if (error < 0)
        {
            MessageError(error);
        }
    }

    return m;
}

void PrintMusic(Music m)
{
    printf("\n- Music: %s\n", m.name);
    printf("\n- Album: %s\n", m.album);
    printf("\n- Artist: %s\n", m.artist);
    printf("\n- Style: %s\n", m.style);
    printf("\n- Duration (MM:SS): %i:%i\n", m.duration.min, m.duration.sec);
}
int ValidDuration(int min, int sec)
{
    if (min < 0)
    {
        return -5;
    }
    else if (sec >= 60 || sec < 0)
    {
        return -6;
    }
    else if (sec == 0 && min == 0)
    {
        return -7;
    }
}
int ListPlaylist()
{
    int i;

    if (NumMusic <= 0)
    {
        return -2;
    }
    system("cls");

    for (i = 0; i < NumMusic; i++)
    {
        printf("\n-- Track [%i] --\n", i + 1);
        PrintMusic(PlayList[i]);
    }

    return 1;
}
int Alternate()
{
    int track = -1;
    if (NumMusic <= 0)
    {
        return -2;
    }
    while (track < 0 || track >= NumMusic)
    {
        ListPlaylist();
        printf("\nEnter the track you want to switch: [ %i - %i]:", 1, NumMusic);
        scanf("%i", &track);
        fflush(stdin);
        track--;
        if (track < 0 || track >= NumMusic)
        {
            MessageError(-8);
        }
        else
        {
            SwitchTrack(track);
        }
    }
    system("cls");
    PrintMusic(PlayList[track]);
    return 1;
}
void SwitchTrack(int track)
{

    int error = -1;

    printf("\nMusic name:\n");
    gets(PlayList[track].name);
    fflush(stdin);

    printf("\nAlbum:\n");
    gets(PlayList[track].album);
    fflush(stdin);

    printf("\nArtist:\n");
    gets(PlayList[track].artist);
    fflush(stdin);

    printf("\nStyle:\n");
    gets(PlayList[track].style);
    fflush(stdin);

    while (error < 0)
    {
        printf("\nDuracao (MM SS):\n");
        scanf("%i%i", &PlayList[track].duration.min, &PlayList[track].duration.sec);
        fflush(stdin);
        error = ValidDuration(PlayList[track].duration.min, PlayList[track].duration.sec);
        if (error < 0)
        {
            MessageError(error);
        }
    }
}