inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
ת�˼����䣬��һ�Ų��������д��˳�ȥ����ʱ���ô��ˡ�
��ǰһƬ����������϶�����һ�����ٲ���ˮ���Ľ����չ�ӳ
�գ��ֳ�һ���ʺ磬���ܻ����β�ӻ������䣬��ӳ�ڱ�
�̵ĺ�ˮ֮�У�����Ī����Զ���Ǵ�Ƭ���ƽԭ���ޱ��޼ʵ�
�����ȥ��������ӡ�
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
		"south" : __DIR__"caoyuan1",
		"east" : __DIR__"lake3",
		"west" : __DIR__"huijiang5",
	]));

        setup();
        replace_program(ROOM);
}
