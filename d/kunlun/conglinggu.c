inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",@long
�����ǰͻȻΪ֮һ����ֻ��һ����һ��������Ͽ����
ʯ�䣬��ɽ��ѩˮк�䵽ǧ�����µ�ɽ����ȥ����������ܵ�
��ĭ����һ�־��Ķ��ǵ��𺶡���������ɽҰ�ȵ�Ϫ���ߣ�ȴ
�����˸��ָ����Ļ�����ľ�����췱������Ͽ�������ʵѹ��
ɽ�����˼����������������ǵ���԰��
long);
        set("exits",([
                "south" : __DIR__"shanlin" + (random(5) + 1),
        ]));

        set("objects", ([
                "/clone/herb/huangqi"   : random(2),
                "/clone/herb/chongcao"  : random(2),
                "/clone/herb/qianjinzi" : random(2),
                "/clone/herb/fuzi"      : random(2),
                "/clone/herb/renshen"   : random(2),
                "/clone/herb/mahuang"   : random(2),
        ]));

        setup();
        replace_program(ROOM);
}
