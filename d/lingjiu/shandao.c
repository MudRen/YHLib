inherit ROOM;

void create()
{
  	set("short", "ƽ̨ɽ��");
  	set("long", @LONG
ɽ����һ����ӥ�ͻ���ľ��ҽضϣ����ҹ�ɼ��ˣ�ֻ��
�м������һ��խխ��ʯ��ͨ��ɽ������һͷ����С�������
����̤����ȥ���Ҳ���һ���ƽ̨����ϡ��ȥ�����в�������
����ۻᡣ
LONG );
        set("outdoors", "lingjiu");
        set("exits", ([
                "west" : __DIR__"yan",
                "east" : __DIR__"pingtai",
                "north" : __DIR__"shandao2",
                "south" : __DIR__"pingtai3",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/duanmu" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
