#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�����"NOR);
        set("long", @long
���۶��򱱣��ֹ���һ�룬ֻ���Ű����Ѱ����£���ֱͦ
���㣬�����и����ԣ������ض���������ݱ���߳�ʮ���ɣ�ֻ
��������֮���������������ϸϸ���������������ƺ�����
����Ӧ�𣬼��عأ���ת������ֻ�������������һ������
���ӱ��������ϥ�Ϸ���һ�Ž�β�٣����Ե��ࡣ��������ľ
��ͣ������ȸ����ݺ���ž飬ϲȵ���˸磬������಻֪����
�ģ���������һ��һ�𣬻������ͳ���
long);
	set("exits", ([
		"south" : __DIR__"sanshengao",
	]));

	set("objects",([
                CLASS_D("kunlun") + "/hezudao" : 1,
    	]));

        set("outdoors", "kunlun");
        setup();
	replace_program(ROOM);
}
