inherit ROOM;

int do_knock(string arg);

void create()
{
        set("short", "�������᷿");
        set("long", @LONG
����Ƕ��᷿���������øɸɾ���������¶�������̵�
֦Ҷ���Ҿ���һ����Ⱦ���������źܴ�����ש��һ��ҳ�Ҳ
��մ��
LONG);
        set("exits", ([
               "west"   : __DIR__"liufudating",
        ]));

        set("objects", ([
                __DIR__"npc/liufuren" : 1,
        ]));

        setup();
	replace_program(ROOM);
}
