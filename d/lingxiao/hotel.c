inherit ROOM;

void create()
{
        set("short", "��ѩ��");
        set("long", @LONG
�����������������ľ�¥��ѩ����ͬʱҲ�������ǵ�����
֮һ���󷲹����ÿͣ������Ƿ������䣬��������ī�ͣ�Ǩ��ɧ
�ˣ���Ҫ����һ������л�̿Ͷ��������ǣ��ڴ˿���ʮ��̳��
��֮��ɱ�������ڳǡ��Ӵˣ������Ǳ�ѩ���Ĵ�������������
�ĺ���
LONG);
        set("exits", ([
                "east" : __DIR__"iceroad1",
        ]));
        set("objects", ([
                "/d/city/npc/xiaoer2" : 1,
                __DIR__"npc/dizi" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

