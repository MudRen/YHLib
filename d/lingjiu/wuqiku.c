inherit ROOM;

void create()
{
        set("short", "ޤ����");
        set("long", @LONG
�������չ����ӵı����⣬�㻷�����ܣ�����ǽ��Ƕ����
��ʽ��������ϸһ����ԭ����ǽ���ھ������������֮�οٳ�
���ӣ����о����ڲ��ڡ�
LONG);
        set("exits", ([
                "east" : __DIR__"changl5",
        ]));
        set("objects",([
                "/d/village/obj/zhujian" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
