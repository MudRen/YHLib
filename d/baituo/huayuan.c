inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
���Ǹ������Ĵ�԰��԰�������������޵ĺ�õ�塣����
��Ů����������Ϸ���������������Ļ���������ͨ��ɽׯ����
��ط��������ǳ����������ǰ���ɽ����ŷ���˵����ң�����
���ţ�Ҳ��֪�����ڲ��ڡ�
LONG);
        set("outdoors", "baituo");
        set("exits",([
                "west"  : __DIR__"neishi",
                "north" : __DIR__"zhuyuan",
                "east"  : __DIR__"chufang",
                "south" : __DIR__"menlang",
        ]));

        set("objects",([
                __DIR__"npc/whitelady" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
