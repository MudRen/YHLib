inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶����ϱ���ȥ��������һ�����ֵĹ㳡��������
һ��С�Թݣ�������ζƮ��������ֱ����ˮ��
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "west" : __DIR__"xiaochidian",
                "east" : __DIR__"majiu",
                "south" : __DIR__"beidajie1",
                "north" : __DIR__"beimen",
        ]));
        set("objects", ([
                "/d/beijing/npc/kid1" : 1,
                "/d/beijing/npc/old1" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
