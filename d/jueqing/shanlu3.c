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
               "northwest"   : __DIR__"houshan",
               "southeast"   : __DIR__"zhulin2",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
