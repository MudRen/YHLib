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
                "northup" : __DIR__"shijie7",
                "southdown" : __DIR__"jiaobei",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
