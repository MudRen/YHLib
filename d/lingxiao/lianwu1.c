inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ǵ����䳡�����Ϸ��ż���ľ�ˣ��ǹ���������
����֮�á��������������ֳֳ������������������ڳ���������
����
LONG );
        set("exits", ([
            "east"      : __DIR__"fudian1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "lingxiao" );
        setup();
        replace_program(ROOM);
}

