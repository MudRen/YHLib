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
                "southeast" : __DIR__"shijie3",
                "southdown" : __DIR__"shijie1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
