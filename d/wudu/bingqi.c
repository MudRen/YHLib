inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������嶾�̴�������ĵط������濿ǽȫ�Ǳ����ܣ��������
�˸��ֱ�����  
LONG);

        set("exits", ([
                "west" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  __DIR__"obj/ganggou": 2,
                  __DIR__"obj/woodjian": 2,
        ]));
    
        setup();
        replace_program(ROOM);
}

