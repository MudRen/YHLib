inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶���������ȥ��������һ�����ֵĹ㳡�����ߴ�
��һ��������ײ�����������Ƕ���һ�����ֺŵ����š�
LONG);
        set("outdoors", "lanzhou");
        set("exits", ([
                "south" : __DIR__"nandajie2",
                "north" : __DIR__"guangchang",
                "east" : __DIR__"qianzhuang",
        ]));
        set("objects", ([
                "/d/beijing/npc/richman1" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
