inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�������ʯ��·����ɽ����������ɽ�Ƶ���������
���ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ�
���ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"banshanting",
                "southdown" : __DIR__"shijie4",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
