inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������һ��ʯ���̳ɵ�С·�ϣ������Ǹߴ�Ĵ���������
�����ƻ�����գ�������ˬ���ˡ���Ϊ�������ܶ�������λ��
�ҵĳ���֮�أ�����·Ҳ�����ĺܺá�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_penquan",
  		"north" : __DIR__"hh_woshi",
	]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
