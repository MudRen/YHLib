inherit ROOM;

void create()
{
        set("short", "ˮ��");
        set("long", @LONG
����һƬ����ƽ�ص�ũ������﹡��ȫ������ˮ��û�š�
һЩ���Ჿ�ĸ�Ů���Ž�������������������ˮ���㣬��
Ȼû�н��������������ر��ȣ�ÿ������������Ȼ��ˮ������
LONG);
        set("objects", ([
                __DIR__"npc/nongfu1" : 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "north" : __DIR__"luwang",
        ]));
        setup();
        replace_program(ROOM);
}
