inherit ROOM;

void create()
{
    	set("short", "��");
    	set("long", @LONG
�����������ܵ���һ���ݼ��������ݼ�����ʮ����·��ǰ
���Ȼ���ʣ�����һ��Ƭƽ�ء�
LONG);
    	set("exits", ([ 
  		"down" : __DIR__"feicui1",
  		"out" : __DIR__"yushi",
	]));
    	setup();
    	replace_program(ROOM);
}
