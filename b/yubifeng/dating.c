// /guanwai/dating.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @long
���������ĽǸ�����һ���̿�����Ͼ��й���һ��ľ�������д��
إ�������֣�"�����ɶ����������޵���,���˼�������������Ӣ��"��
�Ͽ��ǡ�ϣ��������֮�����¿��ǡ��������˷��������������Ϳѻ����
long );
        set("exits", ([
                "south"    : __DIR__"changlang",
                "west"    : __DIR__"zoulang1",
                "east"    : __DIR__"zoulang2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
