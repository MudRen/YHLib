inherit ROOM;

void create()
{
        set("short", "ˮ������");
        set("long", @LONG
������ˮ�����ڶ�����Ȼ�����ⶴ�ߣ���Ҳ��Ϊ��,�˴�
�����ⶴ�����������ü��ٲ������Ĵ���ʯͷ�ϵ��������ߵ�
������ڱ�һ��Ϊ���������������ڡ������￴ȥ���������
�⣬���˲�����Щ�ĺ���
LONG);

	set("exits",([
	      "northwest" : __DIR__"inhole2",
	      "northeast" : __DIR__"inhole3",		
	      "out"       : __DIR__"inhole",	      
	]));	
	     	
       setup();
       replace_program(ROOM);
}

