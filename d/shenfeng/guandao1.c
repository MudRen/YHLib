inherit ROOM;

void create()
{
        set("short", "�ĵ�");
        set("long", @LONG
����ĵ�����һ�ֻƺ�ɫ�����ɫ��ʯ����Ƕ��ϸϸ�Ļ�
ɳ֮�У������Լ������ĸо������������������ԭ���м�
�ش������������Ǳ�����
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : "/d/lanzhou/road",
        ]));
        setup();
        replace_program(ROOM);
}

