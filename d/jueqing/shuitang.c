inherit ROOM;

void create()
{
        set("short", "ˮ��");
        set("long", @LONG
�����˴���ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ��
����ԭ��������ǳǳ��һƬˮ�������ߣ�������ˮ�ɡ���
����������������Ȫ�����µ�����ů�⻨�����Ϸ�֮�Ҳ
��������ĳ��֡�
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "east"   : __DIR__"shanlu1",
               "southdown" : __DIR__"shulin1",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
