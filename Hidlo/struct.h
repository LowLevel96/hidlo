// Struct for File Header ( 14 Bytes )
typedef struct {
        unsigned short int type[2];                 /* Magic identifier            */
        unsigned int size;                       /* File size in bytes          */
        unsigned short int reserved1, reserved2;
        unsigned int offset;                     /* Offset to image data, bytes */
} HEADER;
// Struct for Bitmap Information ( 40 Bytes )
typedef struct {
        unsigned int size;               /* Header size in bytes      */
        int width,height;                /* Width and height of image */
        unsigned short int planes;       /* Number of colour planes   */
        unsigned short int bits;         /* Bits per pixel            */
        unsigned int compression;        /* Compression type          */
        unsigned int imagesize;          /* Image size in bytes       */
        int xresolution,yresolution;     /* Pixels per meter          */
        unsigned int ncolours;           /* Number of colours         */
        unsigned int importantcolours;   /* Important colours         */
} INFOHEADER; 

// Struct for bitmap BGR ( Blue Green Red )
typedef struct {
        unsigned short **bgr;
}BGR;
typedef struct {
        unsigned short **bgr2;
}BGR2;

