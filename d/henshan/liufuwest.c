inherit ROOM;

void create()
{
        set("short", "�������᷿");
        set("long", @LONG
��������᷿���������øɸɾ���������¶�������̵�
֦Ҷ���Ҿ���һ����Ⱦ���������źܴ�����ש��һ��ҳ�Ҳ
��մ��������С���ǲ�֪����������˵��ʲô��
LONG);
        set("exits", ([
               "east"   : __DIR__"liufudating",
        ]));

        set("objects", ([
                __DIR__"npc/liujing" : 1,
                __DIR__"npc/liuqin"  : 1,
        ]));

        setup();
	replace_program(ROOM);
}
