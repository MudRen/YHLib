inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
һ��С�ɶ����ʵĸ�¥�����Ϻõ���ľ��������һ�ɵ���
�����㡣¥�ϵ����Ӿ���һ���ǧ��ǵ�������¸�ɮ����
���£���ʩ���ɵġ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"qianyuan",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
