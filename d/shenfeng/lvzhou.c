inherit ROOM;

void create()
{
        set("short", "ɳĮ����");
        set("long", @LONG
����µ���ɳ�Ѿ�������һ��СС�ĺ��������������ǰ��
�����ˮ��Ȼֻ�ж�ָ��ȴ���峺���ڿ��ȵķ��У���ˮ��
����ô��������һ�������ɱ�����ע����С�����������һ��
ѩ�׵�ɽ���������������ۣ��羴֮�ģ���Ȼ������
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
  		"east" : __DIR__"shamo3",
  		"west" : __DIR__"xiaojing",
  		"north" : __DIR__"lake1",
	]));
        setup();
        replace_program(ROOM);
}
