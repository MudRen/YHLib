#include <ansi.h>
inherit ROOM;

void create()
{
      	set("short", "���ҹ���̨");
      	set("long", @LONG
�����Ǿ������ҹ���̨����̨�����²࣬������Ԩ���
�ɲ⡣ɽ��ж���������棬�پ����ϴ󿪡��䵱���佣���
��������佣�����������е��Ӱ������ϱ���ľ�𡢻�ˮ��
����λ���������Ե��Ӱ�Ǭ�����������롢�㡢���ޡ��Ұ�
���졢�ء�ˮ���𡢷硢�ס�ɽ�������С�
LONG);
      	set("objects", ([
           	CLASS_D("wudang") +"/wuxing": 5,
           	CLASS_D("wudang") +"/bagua": 8,
           	CLASS_D("wudang") +"/yan": 1,
      	]));
      	set("exits",([
          	"northdown" : __DIR__"nanyangong",
      	]));
      	set("outdoors", "wudang");
      	setup();
      	replace_program(ROOM);
}
