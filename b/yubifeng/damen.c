// /guanwai/damen.c

inherit ROOM;

void create()
{
        set("short", "ɽׯ����");
        set("long", @long
ת���˼���ѩ��,ֻ��ǰ��һ���忪�伫���ʯ�ݣ���ǰ�ݺ��ǰ�ѩ��
������д�š���ʷ�ɽׯ���������֣��˴�����Ắ�����¼��ѣ�������
֪��ׯ�����˶��ٵ���˼�����ڴ˽������ʯ�ң����������������档
long );
        set("exits", ([
                "enter"    : __DIR__"changlang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
