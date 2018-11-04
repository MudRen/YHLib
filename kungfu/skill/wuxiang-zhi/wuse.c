// wuse.c  ��ɫ����
         
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 
        
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("����ɫ���ࡹֻ����ս���жԶ���ʹ�á�\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʹ�á���ɫ���ࡹ��\n"); 
         
        if (me->query_skill("force") < 100) 
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n"); 
        
        if (me->query_skill("xuxiang-zhi", 1) < 150) 
                return notify_fail("�������ָ��Ϊ������Ŀǰ����ʹ�á���ɫ���ࡹ��\n"); 
         
        if (me->query("neili") < 400) 
                return notify_fail("��������������޷�ʹ�á���ɫ���ࡹ��\n"); 
         
        if (me->query_skill_mapped("finger") != "wuxiang-zhi") 
                return notify_fail("��û�м�����������ָ������ʹ�á���ɫ���ࡹ��\n"); 

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ȫ�������������ָ��������ϣ�" 
              HIY "��$n��ȥ��ͬʱһָ��������ͬ����һ�����$n" + HIY "��\n" NOR; 
         
        ap = me->query_skill("finger") + me->query_skill("force"); 
        dp = target->query_skill("dodge") + target->query_skill("parry"); 
         
        if (ap / 2 + random(ap) > dp) 
        { 
                damage = ap / 2 + me->query_skill("buddhism", 1) / 2; 
                me->add("neili", -200); 
         
                msg += HIR "ֻ��$p" HIR "һ���ҽУ��ѱ������ؿ�ҪѨ��" 
                       "$p" HIR "ֻ�����ؿ���Ѫ��ӿ��ȫ����Ѫ" 
                       "�������۵�һ���³�һ����Ѫ���಻���ԣ�\n" NOR;
		msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 70); 
        } else 
        { 
                me->add("neili", -100); 
                me->start_busy(3); 
                msg += CYN "����$p" CYN "������$N" CYN "����ͼ������" 
                       CYN "���Ʈ�����ɣ��������һ������һ����\n"NOR; 
        } 
                message_combatd(msg, me, target); 
         
                return 1; 
}
