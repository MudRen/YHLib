inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���ô˴���һ·�����Ƿ����ʤ��ֻ��·���ɺ���������
¹��Ⱥ������С�ã����Ǽ��˲�����ż���ŵ�����Ļ��㣬��
�����԰��á�С¹��ȥ��Ծ�����ǿɰ��������Ŀ�������
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "northup"      : __DIR__"jueqing",
               "southeast"    : __DIR__"shanlu7",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
