inherit ROOM; 
 
void create ()
{
  	set ("short", "��԰");
  	set ("long", @LONG
һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��Ҳ���õþ��¿��ˡ�
��Զ�ھ�����Ȼ��������֮ʿ���������һ�ʢ�������ճ�����ɻ��������
��ջ����ޣ���������һƬ��ѩ����
LONG);

  	set("exits", ([
  		"east" : __DIR__"c_garden",
  		"south" : __DIR__"pianting",
	]));

	setup(); 
	replace_program(ROOM); 
} 
