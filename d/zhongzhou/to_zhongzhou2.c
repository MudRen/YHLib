inherit ROOM;

void create()
{
  	set ("short", "���ݵ�");
  	set ("long", @LONG
�����������ϱ��Ľ�ͨҪ�����������˲��ϡ����Ե���ľ
�¶�����С��������ˡ����������ݳǣ�����ͨ�����ݡ�
LONG);

  	set("outdoors", "zhongzhou");
  	set("exits", ([
  		"south" : __DIR__"to_zhongzhou3",
  		"north" : __DIR__"to_zhongzhou",
	]));

  	setup();
}
